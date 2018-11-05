import bottle
import time
from bottle import get, run, template

data = {}
data["states"] =["Dead Man's Switch", "idle", "forward", "left", "right", "leftforward", "rightforward", "backward", "leftbackward", "rightbackward", "moving"]
data["state"] = "idle"
data["lastTime"] = -1

@get("/setstate/<state>")
def index(state):
    global data
    data["lastTime"] = time.time()
    if state in data["states"]:
        data["state"] = state
    return "Ok."

@get("/getstate")
@get("/getstate/")
def state():
    global data
    if time.time() > data["lastTime"] + 0.1:
        data["state"] = "idle"
    return data["state"]
    # return "forward"

# Set this to the servers IP you probably need to change this every time you run this
IP = "10.0.80.31"
PORT = 8080 # 8080 is standard debug port
if __name__=="__main__":
    # run(host=IP, port=8080, quiet=True)
    run(host=IP, port=PORT, quiet=False)
