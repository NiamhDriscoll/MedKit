import json
import time
from datetime import datetime

time.time()

print("hello")
while True:
    with open('time.json', 'r') as medication_time:
        data = json.load(medication_time)
    with open('medication.json', 'r') as medication:
         meds = json.load(medication)
    time_only = datetime.now().strftime("%H:%M")

    day = datetime.now().strftime("%a")
    time_key = f"{day}Time"
    med_time = data[time_key]
    med_key = f"{day}"
    med_write = meds[med_key]
    if time_only == med_time:
     with open('med.txt', 'w') as med:
        med.write(str(med_write))
        with open('bool.txt', 'w') as bool_file:
            bool_file.write("True")

            time.sleep(60)











