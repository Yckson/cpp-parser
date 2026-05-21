import sys
import os
import json
import platform
import subprocess

HTML_TEMPLATE = """<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Visualizador de Diff - __FILENAME__</title>
    <style>
        :root {
            --bg-color: #0d1117;
            --surface-color: #161b22;
            --border-color: #30363d;
            --text-color: #c9d1d9;
            --muted-text: #8b949e;
            
            --add-bg: #1a3022;
            --add-num-bg: #20402b;
            --add-border: #2ea043;
            
            --rem-bg: #341a1f;
            --rem-num-bg: #502428;
            --rem-border: #f85149;
            
            --chunk-bg: #182c44;
            --chunk-num-bg: #1f3e62;
            --chunk-text: #58a6ff;
            --chunk-border: #388bfd;
        }

        body {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Helvetica, Arial, sans-serif;
            background-color: var(--bg-color);
            color: var(--text-color);
            margin: 0;
            padding: 20px;
        }

        .container {
            max-width: 1200px;
            margin: 0 auto;
        }

        header {
            margin-bottom: 20px;
            padding: 10px 20px;
            background: var(--surface-color);
            border: 1px solid var(--border-color);
            border-radius: 6px;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }

        header h1 {
            font-size: 18px;
            margin: 0;
        }

        .diff-wrapper {
            background: var(--surface-color);
            border: 1px solid var(--border-color);
            border-radius: 6px;
            overflow: hidden;
            box-shadow: 0 1px 3px rgba(0,0,0,0.05);
        }

        .diff-row {
            display: flex;
            font-family: ui-monospace, SFMono-Regular, SF Mono, Menlo, Consolas, Liberation Mono, monospace;
            font-size: 12px;
            line-height: 20px;
        }

        .diff-row:hover {
            background-color: rgba(255, 255, 255, 0.05);
        }

        .line-num {
            width: 40px;
            min-width: 40px;
            padding: 0 10px;
            text-align: right;
            color: var(--muted-text);
            border-right: 1px solid var(--border-color);
            user-select: none;
            cursor: pointer;
        }

        .diff-content {
            padding-left: 10px;
            white-space: pre-wrap;
            width: 100%;
            word-break: break-all;
        }

        .file-header {
            font-weight: bold;
            background-color: var(--bg-color);
            padding: 10px;
            border-bottom: 1px solid var(--border-color);
            align-items: center;
        }
        .file-header .line-num { display: none; }
        .file-header .diff-content { padding-left: 0; font-size: 14px; }

        .chunk-header {
            background-color: var(--chunk-bg);
            color: var(--chunk-text);
        }
        .chunk-header .line-num { background-color: var(--chunk-num-bg); border-color: var(--chunk-border); }

        .line-added { background-color: var(--add-bg); }
        .line-added .line-num { background-color: var(--add-num-bg); border-color: var(--add-border); }

        .line-removed { background-color: var(--rem-bg); }
        .line-removed .line-num { background-color: var(--rem-num-bg); border-color: var(--rem-border); }

    </style>
</head>
<body>
    <div class="container">
        <header>
            <h1>Revisão de Diff</h1>
            <span style="font-family: monospace; color: var(--muted-text);">__FILENAME__</span>
        </header>
        
        <div class="diff-wrapper" id="diff-view">
            <!-- JavaScript vai renderizar o conteúdo aqui -->
        </div>
    </div>

    <script>
        // O Python injetará o conteúdo do arquivo diff na variável abaixo
        const rawDiff = __DIFF_DATA__;
        
        function renderDiff(diffText) {
            const lines = diffText.split('\\n');
            const container = document.getElementById('diff-view');
            
            let oldLine = 0;
            let newLine = 0;

            lines.forEach(line => {
                // Ignora linhas vazias no final do arquivo
                if (line === '' && lines[lines.length - 1] === line) return;

                const row = document.createElement('div');
                row.className = 'diff-row';

                const oldNumCol = document.createElement('div');
                oldNumCol.className = 'line-num';
                
                const newNumCol = document.createElement('div');
                newNumCol.className = 'line-num';
                
                const contentCol = document.createElement('div');
                contentCol.className = 'diff-content';

                // Tratamento de cabeçalhos de arquivo (--- / +++)
                if (line.startsWith('---') || line.startsWith('+++')) {
                    row.classList.add('file-header');
                    contentCol.textContent = line;
                } 
                // Tratamento de bloco de diferenças (@@ -x,y +z,w @@)
                else if (line.startsWith('@@')) {
                    row.classList.add('chunk-header');
                    contentCol.textContent = line;
                    
                    const match = line.match(/@@ -(\\d+)(?:,\\d+)? \\+(\\d+)(?:,\\d+)? @@/);
                    if (match) {
                        oldLine = parseInt(match[1], 10);
                        newLine = parseInt(match[2], 10);
                        oldNumCol.textContent = '...';
                        newNumCol.textContent = '...';
                    }
                } 
                // Linha adicionada
                else if (line.startsWith('+')) {
                    row.classList.add('line-added');
                    newNumCol.textContent = newLine++;
                    contentCol.textContent = line;
                } 
                // Linha removida
                else if (line.startsWith('-')) {
                    row.classList.add('line-removed');
                    oldNumCol.textContent = oldLine++;
                    contentCol.textContent = line;
                } 
                // Linha de contexto (não modificada)
                else if (line.startsWith(' ')) {
                    row.classList.add('line-context');
                    oldNumCol.textContent = oldLine++;
                    newNumCol.textContent = newLine++;
                    contentCol.textContent = line;
                } 
                // Outros metadados (ex: \\ No newline at end of file)
                else {
                    row.style.color = 'var(--muted-text)';
                    contentCol.textContent = line;
                }

                if (!row.classList.contains('file-header')) {
                    row.appendChild(oldNumCol);
                    row.appendChild(newNumCol);
                }
                row.appendChild(contentCol);
                container.appendChild(row);
            });
        }

        // Inicia a renderização
        renderDiff(rawDiff);
    </script>
</body>
</html>
"""

def main():
    if len(sys.argv) < 2:
        print("Uso: python diff_viewer.py <caminho_para_o_arquivo.diff>")
        sys.exit(1)

    diff_file_path = sys.argv[1]

    if not os.path.exists(diff_file_path):
        print(f"Erro: O arquivo '{diff_file_path}' não foi encontrado.")
        sys.exit(1)

    # Lê o conteúdo do diff
    try:
        with open(diff_file_path, 'r', encoding='utf-8') as f:
            diff_content = f.read()
    except UnicodeDecodeError:
        # Fallback caso o arquivo tenha encoding diferente
        with open(diff_file_path, 'r', encoding='latin-1') as f:
            diff_content = f.read()

    # Prepara os dados para injeção no template
    filename = os.path.basename(diff_file_path)
    safe_diff_data = json.dumps(diff_content) # Serializa como string JS de forma segura

    # Substitui os placeholders no template
    html_output = HTML_TEMPLATE.replace('__FILENAME__', filename)
    html_output = html_output.replace('__DIFF_DATA__', safe_diff_data)

    # Define o nome do arquivo de saída e escreve o HTML
    output_filename = f"{filename}.html"
    output_path = os.path.abspath(output_filename)
    
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(html_output)

    print(f"Sucesso! Página gerada em: {output_path}")
    
   
if __name__ == "__main__":
    main()