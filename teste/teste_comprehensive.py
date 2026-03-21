"""Comprehensive Python parser test file"""

def simple_func(x, y):
    """Calculate sum"""
    z = x + y
    return z


class DataProcessor:
    """Process data"""

    def __init__(self, name):
        self.name = name

    def process(self, items):
        result = []
        for item in items:
            if item > 0:
                result.append(item)
            else:
                continue
        return result


def handle_errors(filename):
    """Handle file operations"""
    try:
        with open(filename, 'r') as f:
            data = f.read()
    except FileNotFoundError:
        print("File not found")
    except IOError as e:
        print(f"IO error: {e}")
    finally:
        print("Done")


def loop_control():
    """Test loop control structures"""
    i = 0
    while i < 10:
        if i == 5:
            break
        i += 1

    for x in range(5):
        if x == 2:
            continue
        print(x)


def pattern_matching(value):
    """Python 3.10+ pattern matching"""
    match value:
        case 1:
            return "one"
        case 2:
            return "two"
        case _:
            return "other"


def context_manager():
    """Test with statement"""
    with open("file.txt") as f:
        data = f.read()

    return data


def lambda_test():
    """Lambda and assertions"""
    f = lambda x: x * 2
    assert f(5) == 10
    return f
