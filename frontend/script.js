const BASE_URL = "http://127.0.0.1:5000";

function updateOutput(data) {
    document.getElementById("outputBox").innerHTML = data;
}

function performTransaction() {
    const file = document.getElementById("file").value;
    const data = document.getElementById("data").value;

    fetch(`${BASE_URL}/transaction?file=${file}&data=${data}`)
        .then(res => res.text())
        .then(data => updateOutput(data));
}

function simulateCrash() {
    const file = document.getElementById("file").value;
    const data = document.getElementById("data").value;

    fetch(`${BASE_URL}/crash?file=${file}&data=${data}`)
        .then(res => res.text())
        .then(data => updateOutput(data));
}

function runRecovery() {
    fetch(`${BASE_URL}/recovery`)
        .then(res => res.text())
        .then(data => updateOutput(data));
}

function showCache() {
    fetch(`${BASE_URL}/cache`)
        .then(res => res.text())
        .then(data => updateOutput(data));
}

function clearLogs() {
    fetch(`${BASE_URL}/clear`)
        .then(res => res.text())
        .then(data => updateOutput(data));
}