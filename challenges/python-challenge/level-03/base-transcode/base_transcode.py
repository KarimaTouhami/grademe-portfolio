def convert_base_digits(number: str, source_base: int, target_base: int) -> str:
    if not (2 <= source_base <= 36) or not (2 <= target_base <= 36):
        return "invalid"
        
    if not number:
        return "invalid"

    CHAR_MAP = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
    decimal_val = 0
    for char in number.upper():
        if char not in CHAR_MAP:
            return "invalid"
            
        value = CHAR_MAP.index(char)
        
        if value >= source_base:
            return "invalid"
            
        decimal_val = decimal_val * source_base + value

    if decimal_val == 0:
        return "0"

    result_chars = []
    while decimal_val > 0:
        remainder = decimal_val % target_base
        result_chars.append(CHAR_MAP[remainder])
        decimal_val //= target_base

    return "".join(result_chars[::-1])