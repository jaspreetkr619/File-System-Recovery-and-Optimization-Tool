const BASE_URL = "http://127.0.0.1:5000";

function updateOutput(data) {
    console.log("OUTPUT:", data);
    document.getElementById("outputBox").textContent = data;
}

// Attach events AFTER page loads
window.onload = function () {

    // ================= TRANSACTION =================
    document.getElementById("txnBtn").addEventListener("click", function (e) {
        e.preventDefault();

        const file = document.getElementById("file").value;
        const data = document.getElementById("data").value;

        if (!file || !data) {
            updateOutput("Please enter file and data.");
            return;
        }

        fetch(`${BASE_URL}/transaction?file=${file}&data=${data}`)
            .then(res => res.text())
            .then(updateOutput);
    });

    // ================= CRASH =================
    document.getElementById("crashBtn").addEventListener("click", function (e) {
        e.preventDefault();

        const file = document.getElementById("file").value;
        const data = document.getElementById("data").value;

        if (!file || !data) {
            updateOutput("Please enter file and data.");
            return;
        }

        fetch(`${BASE_URL}/crash?file=${file}&data=${data}`)
            .then(res => res.text())
            .then(updateOutput);
    });

    // ================= RECOVERY =================
    document.getElementById("recBtn").addEventListener("click", function (e) {
        e.preventDefault();

        fetch(`${BASE_URL}/recovery`)
            .then(res => res.text())
            .then(updateOutput);
    });

    // ================= CACHE =================
    document.getElementById("cacheBtn").addEventListener("click", function (e) {
        e.preventDefault();

        fetch(`${BASE_URL}/cache`)
            .then(res => res.text())
            .then(updateOutput);
    });

    // ================= CLEAR =================
    document.getElementById("clearBtn").addEventListener("click", function (e) {
        e.preventDefault();

        fetch(`${BASE_URL}/clear`)
            .then(res => res.text())
            .then(updateOutput);
    });

    // ================= LIST FILES (FIXED) =================
    document.getElementById("listBtn").addEventListener("click", function (e) {
        e.preventDefault();

        fetch(`${BASE_URL}/list`)
            .then(res => res.text())
            .then(updateOutput);
    });

    // ================= SEARCH FILE (FIXED) =================
    document.getElementById("searchBtn").addEventListener("click", function (e) {
        e.preventDefault();

        const file = document.getElementById("file").value;

        if (!file) {
            updateOutput("Please enter a file name to search.");
            return;
        }

        fetch(`${BASE_URL}/search?file=${file}`)
            .then(res => res.text())
            .then(updateOutput);
    });

};