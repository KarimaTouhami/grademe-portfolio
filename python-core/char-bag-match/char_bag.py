def same_character_bag(left: str, right: str) -> bool:
    def get_counts(text: str) -> dict:
        counts = {}
        for char in text:
            if char in counts:
                counts[char] += 1
            else:
                counts[char] = 1
        return counts

    return get_counts(left) == get_counts(right)