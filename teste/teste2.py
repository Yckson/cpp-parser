def read_file(filename):
    try:
        with open(filename, 'r') as f:
            data = f.read()
            return data
    except FileNotFoundError:
        print("File not found")
        return None
    except IOError:
        print("IO Error")
        return None
    finally:
        print("Cleanup")


def loop_example():
    i = 0
    while i < 10:
        if i == 5:
            break
        i = i + 1
    return i


def match_example(value):
    match value:
        case 1:
            print("One")
        case 2:
            print("Two")
        case _:
            print("Other")
