import json
import time
from datetime import datetime
time.time()
print(time.time())


time.sleep(5)
while True:
    with open('time.json', 'r') as medication_time:
        data = json.load(medication_time)
    with open('time.json', 'r') as medication_time:
         data = json.load(medication_time)
    time_only = datetime.now().strftime("%H:%M")
    day = datetime.now().strftime("%a")
    time_key = f"{day}Time"
    med_time = data[time_key]
    if time_only == med_time:
        print(f"time to take medication: ")
        print(data)

