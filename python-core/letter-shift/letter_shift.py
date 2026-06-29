def shift_letters(text: str, amount: int) -> str:
    result = []
    
    for char in text:
        if char.isalpha():
            start = ord('A') if char.isupper() else ord('a')
            
            shifted_char = chr(start + (ord(char) - start + amount) % 26)
            result.append(shifted_char)
        else:
            result.append(char)
            
    return "".join(result)