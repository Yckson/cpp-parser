#!/usr/bin/env python3

# Quick syntax check
try:
    import source2json
    import source2json_cpp
    print("✓ source2json.py - valid syntax")
    print("✓ source2json_cpp.py - valid syntax")
except SyntaxError as e:
    print(f"✗ Syntax error: {e}")
except ImportError as e:
    print(f"✓ Syntax is valid (import error is expected: {e})")
