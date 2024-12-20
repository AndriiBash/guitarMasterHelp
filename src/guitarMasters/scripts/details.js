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

  if (scrollY >= buttonHeight) {

    if (!isSmallScreen)
    {
      homeButton.textContent = 'Повернутись';
      homeButton.style.transform = 'translateX(-50px)';
    }
    else
    {
      homeButton.textContent = '<';
    }
    buttonWrapper.classList.add('active');
  }
  else {
    if (!isSmallScreen) {
      homeButton.textContent = 'Повернутись';
      homeButton.style.transform = 'translateX(0)';
    }
    else
    {
      homeButton.textContent = 'Повернутись';
    }
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

window.addEventListener('scroll', handleScroll);
