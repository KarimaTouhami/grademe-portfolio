def is_alpha_palindrome(text: str) -> bool:
    clean_chars = []
    for char in text:
        if char.isalpha():
            clean_chars.append(char.lower())
            
    if not clean_chars:
        return False
        
    return clean_chars == clean_chars[::-1]