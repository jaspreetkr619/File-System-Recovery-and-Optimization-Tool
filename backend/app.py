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

        return result.stdout

    except Exception as e:
        return str(e)

if __name__ == "__main__":
    app.run(debug=True)