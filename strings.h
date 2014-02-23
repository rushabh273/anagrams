/*
 * Filename: strings.h
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Strings used in PA3 output
 */


#define STR_USAGE "Usage: %s [--build dictionary_file]\n"

#define STR_BUILD "--build"

#define STR_WRITE_ERR "Whoa! Got a write error on word \"%s\".\n"

#define STR_DATABASE_BUILT " Anagram database file \"%s\" built.\n"

#define STR_STAT_ERR "Stat failed on anagram database file"

#define STR_UNBUILT_DICT "May need to run \"anagrams --build dictionary_file\""\
                      	 " first.\n"

#define STR_CALLOC "Trying to calloc() anagram data structure in memory"

#define STR_FREAD_ERR "Error with fread() of anagram data.\nExpecting %d;"\
           	      " got %d.\n"

#define STR_SEARCH "Enter a word to search for anagrams [^d to exit]: "

#define STR_NO_ANAGRAMS_FOUND "No anagrams found.\n"

#define STR_FOUND_ANAGRAMS "Anagram(s) are:"

#define STR_NEWLINE '\n'
