def zigzag_letters(text: str) -> str:
    result = []
    upper_time = False

    for char in text:
        if char.isalpha():
            if upper_time:
                result.append(char.upper())
            else:
                result.append(char.lower())
            upper_time = not upper_time
        else:
            result.append(char)

    return "".join(result)