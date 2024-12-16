from PIL import Image
import pytesseract

# Load the image from the file path
image_path = "/mnt/data/Screenshot 2024-11-19 185847.png"
image = Image.open(image_path)

# Use Tesseract to extract text from the image
extracted_text = pytesseract.image_to_string(image)
extracted_text