import json
import time
from datetime import datetime
from flask import Flask, render_template
time.time()
app = Flask(__name__)


@app.route("/")
def home():
    return render_template("index.html")

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
        print(f"Time to take medication: ")
        print(meds[day])



        if __name__ == '__main__':
            print("Flask app started")
            try:
                app.run(debug=True, port=8000)
                print("Flask app ended")
            finally:
                print("Flask app closed")
                time.sleep(60)





