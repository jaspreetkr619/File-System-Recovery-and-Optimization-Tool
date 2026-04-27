const BASE_URL = "http://127.0.0.1:5000";

function updateOutput(data) {
    document.getElementById("outputBox").textContent = data;
}

window.onload = function () {

    document.getElementById("txnBtn").onclick = () => {
        const f = file.value;
        const d = data.value;
        fetch(`${BASE_URL}/transaction?file=${f}&data=${d}`)
            .then(r => r.text()).then(updateOutput);
    };

    document.getElementById("crashBtn").onclick = () => {
        const f = file.value;
        const d = data.value;
        fetch(`${BASE_URL}/crash?file=${f}&data=${d}`)
            .then(r => r.text()).then(updateOutput);
    };

    document.getElementById("recBtn").onclick = () => {
        fetch(`${BASE_URL}/recovery`)
            .then(r => r.text()).then(updateOutput);
    };

    document.getElementById("cacheBtn").onclick = () => {
        fetch(`${BASE_URL}/cache`)
            .then(r => r.text()).then(updateOutput);
    };

    document.getElementById("clearBtn").onclick = () => {
        fetch(`${BASE_URL}/clear`)
            .then(r => r.text()).then(updateOutput);
    };

    document.getElementById("listBtn").onclick = () => {
        fetch(`${BASE_URL}/list`)
            .then(r => r.text()).then(updateOutput);
    };

    document.getElementById("searchBtn").onclick = () => {
        const f = file.value;
        fetch(`${BASE_URL}/search?file=${f}`)
            .then(r => r.text()).then(updateOutput);
    };
};