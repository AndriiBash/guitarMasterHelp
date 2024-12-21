function populateDetails(params) {
  const detailsMap = {
    'details-title': 'nickName',
    'details-fio': 'FIO',
    'details-region': 'Region',
    'details-services': 'Services',
    'details-contact': 'ContactNumber',
    'details-rating': 'Rating',
  };

  for (const [elementId, paramName] of Object.entries(detailsMap)) {
    const element = document.getElementById(elementId);
    if (element) {
      element.textContent = params.get(paramName) || 'N/A';
    }
  }
}

function handleScroll() {
  const scrollY = window.scrollY;
  const isSmallScreen = window.innerWidth <= 767;

  if (scrollY > 0) {
    buttonWrapper.classList.add('fixed');
    homeButton.textContent = isSmallScreen ? '<' : 'Повернутись';
  } else {
    buttonWrapper.classList.remove('fixed');
    homeButton.textContent = 'Повернутись';
  }
}

const params = new URLSearchParams(window.location.search);
populateDetails(params);

const imageUrl = params.get('mainPhotoLink') || 'https://via.placeholder.com/600x300';
document.getElementById('master-image').src = imageUrl;

const homeButton = document.querySelector('.home-button');
const buttonWrapper = document.querySelector('.home-button-wrapper');

window.addEventListener('scroll', handleScroll);
