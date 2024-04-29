document.addEventListener('keydown', function(event) {
    if (event.key === 'Shift') {
        alert('Сидоров Иван Николаевич, группа 4131')
    }
});

const images = document.querySelectorAll('.gallery-image');
let currentImageIndex = 0;

function showImage(index) {
    images.forEach((image, i) => {
        if (i === index) {
            image.style.display = 'block';
        } else {
            image.style.display = 'none';
        }
    });
}
function nextImage() {
    currentImageIndex++;
    if (currentImageIndex >= images.length) {
        currentImageIndex = 0;
    }
    showImage(currentImageIndex);
}

showImage(currentImageIndex);
setInterval(nextImage, 3000);