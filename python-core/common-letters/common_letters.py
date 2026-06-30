def common_letters(left: str, right: str) -> str:
    seen = set()
    result = []

    right_set = set(right)
    
    for char in left:
        if char in right_set and char not in seen:
            seen.add(char)
            result.append(char)
            
    return "".join(result)