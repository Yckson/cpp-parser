def grade_student(score):
    if score >= 90:
        return "A"
    elif score >= 80:
        return "B"
    elif score >= 70:
        return "C"
    else:
        return "F"


def check_value(x):
    if x > 0:
        print("positive")
    elif x < 0:
        print("negative")
    else:
        print("zero")
