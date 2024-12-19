function populateDetails(params) {
  document.getElementById('details-title').textContent = params.get('nickName');
  document.getElementById('details-fio').textContent =
    params.get('FIO') || 'N/A';
  document.getElementById('details-region').textContent =
    params.get('Region') || 'N/A';
  document.getElementById('details-services').textContent =
    params.get('Services') || 'N/A';
  document.getElementById('details-contact').textContent =
    params.get('ContactNumber') || 'N/A';
  document.getElementById('details-rating').textContent =
    params.get('Rating') || 'N/A';
}

const params = new URLSearchParams(window.location.search);
populateDetails(params);

const imageUrl =
  params.get('mainPhotoLink') || 'https://via.placeholder.com/600x300';
document.getElementById('master-image').src = imageUrl;

const homeButton = document.querySelector('.home-button');
const buttonWrapper = document.querySelector('.home-button-wrapper');
const buttonHeight = homeButton.offsetHeight;

function handleScroll() {
  const scrollY = window.scrollY;

  if (scrollY >= buttonHeight) {
    homeButton.style.transform = 'translateX(-100%)';
    buttonWrapper.classList.add('active');
  } else {
    homeButton.style.transform = 'translateX(0)';
    buttonWrapper.classList.remove('active');
  }
}

window.addEventListener('scroll', handleScroll);
