// Получаем параметры из URL
const params = new URLSearchParams(window.location.search);

// Заполняем данные на странице
document.getElementById("details-title").textContent =
  params.get("FIO") || "Master Details";
document.getElementById("details-fio").textContent =
  params.get("FIO") || "N/A";
document.getElementById("details-region").textContent =
  params.get("Region") || "N/A";
document.getElementById("details-services").textContent =
  params.get("Services") || "N/A";
document.getElementById("details-contact").textContent =
  params.get("ContactNumber") || "N/A";
document.getElementById("details-rating").textContent =
  params.get("Rating") || "N/A";

// Пример динамической загрузки изображения
const imageUrl =
  params.get("Image") || "https://via.placeholder.com/600x300";
document.getElementById("master-image").src = imageUrl;
