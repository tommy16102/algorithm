/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
const filterWord = (pref) => (word) => word.startsWith(pref);

var prefixCount = function(words, pref) {
    return words.filter(filterWord(pref)).length
};
