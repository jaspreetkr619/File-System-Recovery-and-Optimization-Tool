from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

@app.route("/")
def home():
    return "Backend is running"

if __name__ == "__main__":
    app.run(debug=True)