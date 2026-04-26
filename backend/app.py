from flask import Flask, request, send_from_directory
from flask_cors import CORS
import subprocess
import os
app = Flask(__name__, static_folder="frontend", static_url_path="")
CORS(app)

# 🔹 Get absolute paths once (clean approach)
BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
EXE_PATH = os.path.join(BASE_DIR, "src", "main.exe")


@app.route("/")
def serve_frontend():
    return send_from_directory(app.static_folder, "index.html")


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
        cwd=BASE_DIR
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
        cwd=BASE_DIR
    )

    return result.stdout


@app.route("/recovery")
def recovery():
    result = subprocess.run(
        [EXE_PATH, "recovery"],
        capture_output=True,
        text=True,
        cwd=BASE_DIR
    )

    return result.stdout


@app.route("/cache")
def cache():
    result = subprocess.run(
        [EXE_PATH, "cache"],
        capture_output=True,
        text=True,
        cwd=BASE_DIR
    )

    return result.stdout


@app.route("/clear")
def clear():
    result = subprocess.run(
        [EXE_PATH, "clear"],
        capture_output=True,
        text=True,
        cwd=BASE_DIR
    )

    return result.stdout



if __name__ == "__main__":
    app.run(debug=True)