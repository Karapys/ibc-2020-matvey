import math
import random

def do_for(f, num_of_people, times):
  res = 0
  for i in range(times):
    res += f(num_of_people)
  return res / times

def gen_day_of_birth():
  # Num of a day in year
  return random.randint(1, 365) 

def check_group(num_of_people):
  # Return 1 if group with random numbers of people 
  # satisfies conditions of task.
  births = []
  for man in range(num_of_people):
    births.append(gen_day_of_birth())
  for man_1 in range(num_of_people):
    for man_2 in range(man_1, num_of_people):
      if man_1 == man_2:
        continue
      if births[man_1] == births[man_2]:
        return 1
  return 0


for num_of_people in [22, 23, 70, 367]:
  print(f"Probability with {num_of_people} people: ")
  res = do_for(check_group, num_of_people, 5000)
  print(str(res * 100) + "%")