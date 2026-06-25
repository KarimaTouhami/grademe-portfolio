def sort_ranked_words(words: list[str]) -> list[str]:
    def count_vowels(s: str) -> int:
        vowels = "aeiouAEIOU"
        count = 0
        for char in s:
            if char in vowels:
                count += 1
        return count

    return sorted(words, key=lambda w: (len(w), w.lower(), count_vowels(w)))