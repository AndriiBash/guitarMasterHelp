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
      const value = params.get(paramName) || 'Немає даних';
      console.log(`${paramName}: ${value}`);
      element.textContent = value;
    }
  }

  const linksElement = document.getElementById('details-links');
  if (linksElement) {
    const linksParam = params.get('links');
    if (linksParam) {
      try {
        const links = JSON.parse(linksParam);
        console.log('Links:', links);

        if (typeof links === 'object' && links !== null) {
          linksElement.innerHTML = Object.entries(links)
            .map(([key, url]) => {
              console.log(`${key}: ${url}`);
              let buttonClass = '';
              let iconSrc = '';
              switch (key.toLowerCase()) {
                case 'instagram':
                  buttonClass = 'social-btn instagram';
                  iconSrc = 'https://upload.wikimedia.org/wikipedia/commons/9/95/Instagram_logo_2022.svg';
                  break;
                case 'telegram':
                  buttonClass = 'social-btn telegram';
                  iconSrc = 'https://upload.wikimedia.org/wikipedia/commons/8/82/Telegram_logo.svg';
                  break;
                case 'facebook':
                  buttonClass = 'social-btn facebook';
                  iconSrc = 'https://upload.wikimedia.org/wikipedia/commons/5/51/Facebook_f_logo_%282019%29.svg';
                  break;
                case 'twitter':
                  buttonClass = 'social-btn twitter';
                  iconSrc = 'https://upload.wikimedia.org/wikipedia/commons/c/ce/X_logo_2023.svg';
                  break;
                case 'youtube':
                  buttonClass = 'social-btn youtube';
                  iconSrc = 'https://upload.wikimedia.org/wikipedia/commons/4/42/YouTube_icon_%282013-2017%29.png';
                  break;
                default:
                  buttonClass = 'social-btn default';
                  break;
              }
              return `<button class="${buttonClass}" onclick="window.open('${url}', '_blank')">
                        <img src="${iconSrc}" alt="${key}" class="social-icon" /> ${key}
                      </button>`;
            })
            .join('');
        } else if (Array.isArray(links) && links.length > 0) {
          linksElement.innerHTML = links
            .map(link => {
              console.log(`Link: ${link}`);
              return `<button class="social-btn default" onclick="window.open('${link}', '_blank')">Перейти по посиланню</button>`;
            })
            .join('');
        } else {
          linksElement.textContent = 'N/A';
        }
      } catch (error) {
        console.error('Error parse links:', error);
        linksElement.textContent = 'Error data type';
      }
    } else {
      linksElement.textContent = 'N/A';
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
console.log('Params:', params.toString());
populateDetails(params);

const imageUrl = params.get('mainPhotoLink') || 'https://via.placeholder.com/600x300';
console.log('Image URL:', imageUrl);
document.getElementById('master-image').src = imageUrl;

const homeButton = document.querySelector('.home-button');
const buttonWrapper = document.querySelector('.home-button-wrapper');

window.addEventListener('scroll', handleScroll);
