def loose_anagram(left: str, right: str) -> bool:
    def get_char_counts(text: str) -> dict:
        counts = {}
        for char in text:
            
            if char == ' ':
                continue

            if char.isalpha():
                char = char.lower()

            if char in counts:
                counts[char] += 1
            else:
                counts[char] = 1
        return counts

    return get_char_counts(left) == get_char_counts(right)