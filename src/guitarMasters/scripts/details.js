function populateDetails(params) {
  document.getElementById("details-title").textContent =
    params.get("nickName");
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
}

const params = new URLSearchParams(window.location.search);
populateDetails(params);

const imageUrl =
  params.get("mainPhotoLink") || "https://via.placeholder.com/600x300";
document.getElementById("master-image").src = imageUrl;

const homeButton = document.querySelector('.home-button');

function handleScroll() {
  if (window.scrollY > 100) {
    homeButton.classList.add('sticky');
  } else {
    homeButton.classList.remove('sticky');
  }
}

window.addEventListener('scroll', handleScroll);
