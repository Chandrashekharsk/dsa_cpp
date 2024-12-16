student = {"name": "abhyanshu", "age": 22, "course": "Math"}
items = list(student.items())
for i in range(len(items)):
  key, value = items[i]
  print(f"Item at index {i}: {key} = {value}")