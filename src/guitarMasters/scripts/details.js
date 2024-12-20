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
    document.getElementById(elementId).textContent = params.get(paramName) || 'N/A';
  }
}

function handleScroll() {
  const scrollY = window.scrollY;
  const isSmallScreen = window.innerWidth <= 767;

  if (scrollY >= buttonHeight && !isSmallScreen) {
    homeButton.style.transform = 'translateX(-50px)';
    buttonWrapper.classList.add('active');
  } else {
    homeButton.style.transform = 'translateX(0)';
    buttonWrapper.classList.remove('active');
  }
}

const params = new URLSearchParams(window.location.search);
populateDetails(params);

const imageUrl =
  params.get('mainPhotoLink') || 'https://via.placeholder.com/600x300';
document.getElementById('master-image').src = imageUrl;

const homeButton = document.querySelector('.home-button');
const buttonWrapper = document.querySelector('.home-button-wrapper');
const buttonHeight = homeButton.offsetHeight;

window.addEventListener('resize', () => {
  if (window.innerWidth <= 767) {
    homeButton.style.transform = 'translateX(0)';
    buttonWrapper.classList.add('active');
  }
});