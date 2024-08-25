#pragma once

//header-only library for testing C++ standard library components

#include <random>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iostream>



/**
     * @brief Provides access to the underlying random number generator.
     *
     * This function returns a reference to a static Mersenne Twister engine,
     * ensuring that the generator is only seeded once per application run.
     *
     * @return A reference to a `std::mt19937` random number generator.
     */

inline [[nodiscard]] std::mt19937& urng()
{
    static std::mt19937 eng{ std::random_device{}() };
    return eng;
}

/**
 * @class Irand
 * @brief A class for generating random integers within a specified range.
 *
 * The `Irand` class encapsulates a random number generator that produces
 * integers within a specified range using the Mersenne Twister engine.
 */

class Irand {
public:
    /**
     * @brief Default constructor for the `Irand` class.
     *
     * Constructs an `Irand` object without initializing the distribution range.
     */
    Irand() = default;

    /**
     * @brief Constructs an `Irand` object with a specified range.
     *
     * @param min The lower bound (inclusive) of the range.
     * @param max The upper bound (inclusive) of the range.
     *
     * Initializes the random number generator to produce values in the range [min, max].
     */
    Irand(int min, int max) : m_dist{ min, max } {}

    

    /**
     * @brief Generates a random integer within the specified range.
     *
     * This function overloads the function call operator to produce a random integer
     * within the range [min, max] specified during the construction of the `Irand` object.
     *
     * @return A random integer within the range [min, max].
     */
    [[nodiscard]] int operator()()
    {
        return m_dist(urng());
    }

private:
    std::uniform_int_distribution<int> m_dist;  /**< The distribution used to generate random integers within a specified range. */
};


class Drand {
public:
    Drand() = default;
    Drand(double dmin, double dmax) : m_dist{ dmin, dmax } {}
    [[nodiscard]] double operator()()
    {
        return m_dist(urng());
    }
private:
    std::uniform_real_distribution<double> m_dist;
};

inline [[nodiscard]] std::string rname()
{
	static constexpr const char* pnames[] = {
		"abdi", "abdullah", "abdulmuttalip", "adem", "adnan", "afacan", "agah", "ahmet", "akin", "alev",
"ali", "alican", "alparslan", "anil", "arda", "asim", "askin", "aslican", "aslihan", "ata",
"atakan", "atalay", "atif", "atil", "aycan", "aydan", "aykut", "ayla", "aylin", "aynur",
"ayse", "aytac", "aziz", "azize", "azmi", "baran", "bekir", "belgin", "bennur", "beril",
"berivan", "berk", "beste", "beyhan", "bilal", "bilge", "bilgin", "billur", "binnaz", "binnur",
"birhan", "bora", "bulent", "burak", "burhan", "busra", "cahide", "cahit", "can", "canan",
"candan", "caner", "tamer", "cansu", "cebrail", "celal", "celik", "cem", "cemal", "cemil", "cemile",
"cemre", "cengiz", "cesim", "cetin", "ceyda", "ceyhan", "ceyhun", "ceylan", "cezmi", "cihan",
"cihat", "ciler","cumhur", "cuneyt", "demet", "demir", "deniz", "derin", "derya", "devlet", "devrim", "diana",
"dilber", "dilek", "dogan", "dost", "durmus", "durriye", "ece", "eda", "edip", "ediz",
"efe", "efecan", "ege", "egemen", "emine", "emirhan", "emre", "emrecan", "enes", "engin",
"ercument", "erdem", "esen", "esin", "esra", "eylul", "fadime", "fahri", "fazilet", "feramuz",
"feraye", "ferhat", "ferhunde", "figen", "fikret", "fuat", "fugen", "furkan", "galip", "garo",
"gazi", "gizem", "gul", "gulden", "gulsah", "gulsen", "gunay", "gurbuz", "gursel", "hakan",
"hakki", "haldun", "halime", "haluk", "handan", "hande", "handesu", "hasan", "helin", "hikmet",
"hilal", "hilmi", "hulki", "hulusi", "hulya", "huseyin", "iffet", "irmak", "ismail", "izzet",
"jade", "julide", "kaan", "kamil", "kamile", "kasim", "kaya", "kayahan", "kayhan", "kazim",
"kelami", "kenan", "kerem", "kerim", "keriman", "kezban", "korhan", "kunter", "kurthan", "lale",
"lamia", "leyla", "mahir", "malik", "mehmet", "melek", "melih", "melike", "melisa", "menekse", "mert",
"metin", "mucahit", "muhsin", "mukerrem", "murat", "murathan", "muruvvet", "muslum", "mustafa", "muzaffer", "naci", "naciye",
"nagehan", "nahit", "nalan", "nasrullah", "naz", "nazif", "nazife", "nazli", "necmettin", "necmi",
"necmiye", "nedim", "nefes", "nevsin", "nihal", "nihat", "nisan", "niyazi", "nurdan", "nuri",
"nuriye", "nurullah", "nusret", "okan", "olcay", "onat", "orkun", "osman", "pakize", "papatya",
"pelin", "pelinsu", "perihan", "petek", "pinat", "polat", "polathan", "poyraz", "recep", "refik",
"refika", "rumeysa", "rupen", "saadet", "sabriye", "sade", "sadegul", "sadettin", "sadi", "sadiye",
"sadri", "sadullah", "samet", "sami", "saniye", "sarp", "sefa", "sefer", "selenay", "selin",
"semsit", "sevda", "sevilay", "sevim", "seyhan", "sezai", "sezen", "sezer", "sidre", "sinem",
"soner", "su", "suheyla", "suleyman", "sumeyye", "suphi", "taci", "taner", "tanju", "tansel",
"tansu", "tarcan", "tarik", "tarkan", "tayfun", "tayyar", "tayyip", "tekin", "temel", "teoman",
"teslime", "tevfik", "tijen", "tonguc", "tufan", "tugay", "tugra", "tunc", "tuncer", "turgut",
"turhan", "ufuk", "ugur", "umit", "utku", "yalcin", "yasar", "yasemin", "yasin", "emrecan",
"yavuz", "yelda", "yeliz", "yesim", "yilmaz", "yunus", "yurdagul", "yurdakul", "yurdanur", "yusuf",
"zahide", "zahit", "zarife", "zekai", "necati", "zeliha", "zerrin", "ziya", "zubeyde", };

	return pnames[Irand(0, (int)(std::size(pnames)) - 1)()];
}


//--------------------------------------------------
//--------------------------------------------------
inline [[nodiscard]] std::string rfname()
{
	static constexpr const char* pfnames[] = {
	"acar", "acgoze", "acuka", "ademoglu", "adiguzel", "agaoglu", "akarsu", "akcalar", "akgunes", "akkay",
	"akkuyu", "aklikit", "aksakal", "akyildiz", "akyoldas", "alemdar", "alniacik", "altindag", "altinisik", "altinorak",
	"arcan", "aslan", "avci", "aybeyaz", "aylak", "azmak", "bahceli", "bakirci", "baklavaci", "barutcu",
	"baturalp", "bayraktar", "bekar", "belgeli", "beyaz", "bilgic", "bozkaya", "boztas", "canbay", "candamar",
	"cangoz", "cankoc", "canlikaya", "cansever", "cansiz", "celik", "celiker", "cengaver", "cevikkol", "cilingir",
	"comakci", "corbaci", "cubukay", "cuhadar", "daglarca", "damar", "degirmenci", "demirdogen", "demirel", "derin",
	"dingin", "dokmeci", "dokuzcan", "dosteli", "dumbuk", "dunyalik", "ecevit", "edepli", "edepsiz", "efelik",
	"elebasi", "eliagir", "elibol", "elitemiz", "elkizi", "elmali", "eloglu", "emirkulu", "engerek", "engereke",
	"erdogan", "ergin", "erim", "ersoy", "ertakan", "esbereli", "esnedur", "esteberli", "etci", "ezergecer",
	"fakir", "fedai", "fincan", "firatonu", "fitrat", "gamsiz", "gedik", "geldik", "gilgamis", "girik",
	"girit", "gucsuz", "gultekin", "gumus", "gurkas", "hamsikoylu", "harmanci", "haselici", "hepguler", "hurmaci",
	"iliksiz", "issiz", "jilet", "kabasakal", "kadersiz", "kahraman", "kalemsiz", "kalinkas", "kalpsiz", "kalpten",
	"kapan", "kapici", "kaplan", "kara", "karabatur", "karaduman", "karaelmas", "karakis", "karakoyun", "karakuzu",
	"karamuk", "karaorman", "karasaban", "karataban", "karayel", "kayabasi", "kazanci", "kecisakal", "kelepce", "kelleci",
	"keskin", "kesman", "kilicdar", "kilimci", "kilinc", "kirboga", "kirci", "kocyigit", "kolcak", "komcu",
	"komurcu", "konak", "konca", "koralp", "korukcu", "kosnuk", "kotek", "koylu", "kucukkaya", "kulaksiz",
	"kurban", "kurtulus", "kusmen", "lalezar", "lokmaci", "lombak", "lufer", "maganda", "malazgirt", "malkaciran",
	"mazgirt", "merdane", "mertek", "merzifon", "mirza", "miskin", "miskinoglu", "muglali", "nazik", "nurtopu",
	"olmez", "oltu", "onaran", "ongun", "ordulu", "orhancan", "ormanci", "ortaca", "osmaneli", "otaci",
	"ovacik", "oztoklu", "ozvezneci", "pakdamar", "pirlanta", "polatkan", "portakal", "poturgeli", "reis", "renacan",
	"resimci", "saferikli", "safkan", "salca", "saldiray", "sallabas", "samanci", "saricakir", "sarikafa", "sarpdemir",
	"savaskan", "sefiloglu", "selercan", "semiz", "sener", "serce", "serinsun", "sessiz", "silahdar", "silifkeli",
	"simsek", "sivri", "sofuoglu", "sonmez", "sonuzun", "soylu", "soysalan", "soyubozuk", "sucu", "sulugoz",
	"supuren", "takes", "tamgun", "tamirci", "tantana", "tarumar", "tekinalp", "tekkaya", "tekkilic", "telek",
	"temiz", "temizel", "temizkalp", "tepecik", "tepsici", "tercan", "terlemez", "tertemiz", "tilki", "tokatci",
	"tombeki", "topatan", "topkapi", "tozkoporan", "tufancan", "tunali", "tuzcu", "tuztas", "ufurukcu", "ugursuz",
	"ulakci", "uluocak", "umutsuz", "unalan", "unalmis", "unkapani", "uraz", "uslu", "uyar", "uzay",
	"uzunadam", "yagizeli", "yanardag", "yanardoner", "yangin", "yaracan", "yaradan", "yarma", "yasayavas", "yasli",
	"yasmak", "yavas", "yavasakan", "yaygara", "yelden", "yeldirme", "yeldirmen", "yersiz", "yikilmaz", "yildirim",
	"yilgin", "yilmaz", "yolyapan", "yorganci", "yorgun", "yosun", "yurdakul", "yurekli", "yurekyakan", "yurtsuz",
	"zaimoglu", "zalim", "zengin", "zebani"
	};

	return pfnames[Irand(0, (int)(std::size(pfnames)) - 1)()];

}

constexpr [[nodiscard]] bool isprime(int val) noexcept
{
	if (val < 2)
		return false;

	if (val % 2 == 0)
		return val == 2;

	if (val % 3 == 0)
		return val == 3;

	if (val % 5 == 0)
		return val == 5;

	for (int k = 7; k * k <= val; k += 2)
		if (val % k == 0)
			return false;

	return true;
}


//file operations

inline [[nodiscard]] std::string get_str_from_file(const std::string& filename)
{
	std::ifstream ifs{ filename };
	if (!ifs) {
		std::cerr << "cannot open file\n";
		std::exit(EXIT_FAILURE);
	}
	std::ostringstream oss;
	oss << ifs.rdbuf();

	return oss.str();
}


[[nodiscard]] std::ifstream open_text_file(const std::string& filename)
{
	std::ifstream ifs{ filename };
	if (!ifs) {
		throw std::runtime_error{ filename + " : cannot be opened!\n" };
	}

	return ifs;
}




inline [[nodiscard]] std::ofstream create_text_file(const std::string& filename)
{
	std::ofstream ofs{ filename };

	if (!ofs) {
		throw std::runtime_error{ filename + ": cannot be created!\n" };
	}

	return ofs;
}


inline [[nodiscard]] std::ifstream open_binary_file(const std::string& filename)
{
	std::ifstream ifs{ filename, std::ios::binary };
	if (!ifs) {
		throw std::runtime_error{ filename + " : cannot be opened!\n" };
	}

	return ifs;
}


inline [[nodiscard]] std::ofstream create_binary_file(const std::string& filename)
{
	std::ofstream ofs{ filename, std::ios::binary };

	if (!ofs) {
		throw std::runtime_error{ filename + " : cannot be created!\n" };
	}

	return ofs;
}


