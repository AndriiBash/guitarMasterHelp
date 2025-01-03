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

    const imageUrl = item.mainPhotoLink || 'https://via.placeholder.com/250x150';

    const card = document.createElement("div");
    card.className = "card";
    card.setAttribute("data-index", index);

    card.innerHTML = `
        <img src="${item.mainPhotoLink || "https://via.placeholder.com/250x150"}" alt="${item.nickName}">
        <div class="card-body">
            <div class="card-title">${item.nickName || "NoName"}</div>
            <div class="card-description">
                <strong>${item.FIO || "N/A"}</strong> <br>
                <strong>${item.Region || "N/A"}</strong> <br>
                <strong>Рейтинг: ${item.Rating || "N/A"} </strong>
            </div>
        </div>
    `;

card.addEventListener("click", () => {
  // Преобразуем объект links в строку
  const itemWithEncodedLinks = {
    ...item,
      links: JSON.stringify(item.links || {}) // Преобразуем объект links в строку JSON
    };

    // Формируем строку параметров для URL
    const queryString = new URLSearchParams(itemWithEncodedLinks).toString();

    console.log(queryString); // Проверяем, что запрос сформирован правильно

    // Перенаправляем на details.html с параметрами
    window.location.href = `details.html?${queryString}`;
  });

  container.appendChild(card);
  });
}

function handleScroll() {
  const header = document.querySelector(".sticky-header");
  if (window.scrollY > 18) {
    header.classList.add("scrolled");
  } else {
    header.classList.remove("scrolled");
  }
}

document.addEventListener("scroll", handleScroll);

fetchData();
