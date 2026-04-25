from flask import Flask, request
import subprocess
import os

app = Flask(__name__)

@app.route("/")
def home():
    return "Backend is running"

@app.route("/transaction")
def transaction():
    file = request.args.get("file")
    data = request.args.get("data")

    if not file or not data:
        return "Missing parameters", 400

    try:
        # 🔥 Correct path to main.exe
        exe_path = os.path.abspath(
            os.path.join(os.path.dirname(__file__), "..", "src", "main.exe")
        )

        result = subprocess.run(
            [exe_path, "transaction", file, data],
            capture_output=True,
            text=True
        )

        return "<pre>" + result.stdout + "</pre>"

    except Exception as e:
        return str(e)


@app.route("/crash")
def crash():
    file = request.args.get("file")
    data = request.args.get("data")

    if not file or not data:
        return "Missing parameters", 400

    exe_path = os.path.abspath(
        os.path.join(os.path.dirname(__file__), "..", "src", "main.exe")
    )

    result = subprocess.run(
        [exe_path, "crash", file, data],
        capture_output=True,
        text=True
    )

    return "<pre>" + result.stdout + "</pre>"
@app.route("/recovery")
def recovery():
    exe_path = os.path.abspath(
        os.path.join(os.path.dirname(__file__), "..", "src", "main.exe")
    )

    result = subprocess.run(
        [exe_path, "recovery"],
        capture_output=True,
        text=True
    )

    return "<pre>" + result.stdout + "</pre>"
@app.route("/cache")
def cache():
    exe_path = os.path.abspath(
        os.path.join(os.path.dirname(__file__), "..", "src", "main.exe")
    )

    result = subprocess.run(
        [exe_path, "cache"],
        capture_output=True,
        text=True
    )

    return "<pre>" + result.stdout + "</pre>"
@app.route("/clear")
def clear():
    exe_path = os.path.abspath(
        os.path.join(os.path.dirname(__file__), "..", "src", "main.exe")
    )

    result = subprocess.run(
        [exe_path, "clear"],
        capture_output=True,
        text=True
    )

    return "<pre>" + result.stdout + "</pre>"
if __name__ == "__main__":
    app.run(debug=True)