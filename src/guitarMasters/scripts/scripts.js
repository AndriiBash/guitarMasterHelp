const url =
  "https://qtdatabaseguitar-default-rtdb.europe-west1.firebasedatabase.app/mainTable.json";

async function fetchData() {
  try {
    const response = await fetch(url);
    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }
    const data = await response.json();
    displayCards(data);
  } catch (error) {
    console.error("Error fetching data:", error);
  }
}

function displayCards(data) {
  const container = document.getElementById("card-container");
  container.innerHTML = ""; // Clear existing content

  data.forEach((item, index) => {
    if (!item || !item.FIO) return; // Skip null or invalid entries

    const card = document.createElement("div");
    card.className = "card";
    card.setAttribute("data-index", index);

    card.innerHTML = `
      <img src="https://via.placeholder.com/250x150" alt="${item.FIO}">
      <div class="card-body">
          <div class="card-title">${item.FIO}</div>
          <div class="card-description">
              <strong>Регіон:</strong> ${item.Region || "N/A"}<br>
              <strong>Послуги:</strong> ${item.Services || "N/A"}
          </div>
          <div class="card-footer">
              <strong>Контакт:</strong> ${item.ContactNumber || "N/A"}<br>
              <strong>Рейтинг:</strong> ${item.Rating || "N/A"}
          </div>
      </div>
    `;

    card.addEventListener("click", () => {
      const queryString = new URLSearchParams(item).toString();
      window.location.href = `details.html?${queryString}`;
    });

    container.appendChild(card);
  });
}

fetchData();
