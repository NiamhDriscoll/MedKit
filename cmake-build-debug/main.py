import json
import time
from datetime import datetime
time.time()


time.sleep(1)
while True:
    with open('time.json', 'r') as medication_time:
        data = json.load(medication_time)
    with open('medication.json', 'r') as medication:
         meds = json.load(medication)
    time_only = datetime.now().strftime("%H:%M")

    day = datetime.now().strftime("%a")
    time_key = f"{day}Time"
    med_time = data[time_key]
    if time_only == med_time:
        print(f"time to take medication: ")
        print(meds[day])
        break



