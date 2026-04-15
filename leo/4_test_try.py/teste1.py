def f(x): 
  try: 
    return 10 / x 
  except ZeroDivisionError: 
    return 0 
  finally: 
    print("done")

    