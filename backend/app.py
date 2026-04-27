from flask import Flask, request, send_from_directory, render_template
from flask_cors import CORS
import subprocess
import os
app = Flask(__name__, static_folder='static', template_folder='templates')
CORS(app)

# 🔹 Get absolute paths once (clean approach)

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
PROJECT_ROOT = os.path.abspath(os.path.join(BASE_DIR, ".."))

EXE_PATH = os.path.join(PROJECT_ROOT, "main.exe")

# ✅ ADD THIS ROUTE
@app.route("/")
def home():
    return render_template("index.html")
@app.route("/transaction")
def transaction():
    file = request.args.get("file")
    data = request.args.get("data")

    if not file or not data:
        return "Missing parameters", 400

    result = subprocess.run(
        [EXE_PATH, "transaction", file, data],
        capture_output=True,
        text=True,
    )

    return result.stdout


@app.route("/crash")
def crash():
    file = request.args.get("file")
    data = request.args.get("data")

    if not file or not data:
        return "Missing parameters", 400

    result = subprocess.run(
        [EXE_PATH, "crash", file, data],
        capture_output=True,
        text=True,
    )

    return result.stdout


@app.route("/recovery")
def recovery():
    result = subprocess.run(
        [EXE_PATH, "recovery"],
        capture_output=True,
        text=True,
    )

    return result.stdout

@app.route("/list")
def list_files():
    result = subprocess.run(
        [EXE_PATH, "list"],
        capture_output=True,
        text=True
    )
    return result.stdout

@app.route("/search")
def search_file():
    file = request.args.get("file")

    result = subprocess.run(
        [EXE_PATH, "search", file],
        capture_output=True,
        text=True
    )
    return result.stdout

@app.route("/cache")
def cache():
    result = subprocess.run(
        [EXE_PATH, "cache"],
        capture_output=True,
        text=True,
    )

    return result.stdout


@app.route("/clear")
def clear():
    result = subprocess.run(
        [EXE_PATH, "clear"],
        capture_output=True,
        text=True,
    )

    return result.stdout



if __name__ == "__main__":
    app.run(debug=True)