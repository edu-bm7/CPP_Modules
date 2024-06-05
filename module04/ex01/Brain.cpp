#include "Brain.hpp"
#include <cstdlib>

/*-------------------------------CONSTRUCTORS---------------------------------*/

Brain::Brain()
{
	std::string const ideas[100] = {
			"Today was fun, I explored new places and felt so happy!",
			"Found a cozy spot to nap, life is good.",
			"Met a new friend today, we played and had a great time.",
			"Discovered a yummy treat, what a delicious surprise!",
			"Sunbathed all afternoon, feeling warm and content.",
			"Chased after butterflies, it was so exciting!",
			"Listened to the birds sing, their songs are beautiful.",
			"Found a perfect hiding spot, feeling safe and snug.",
			"Played with leaves, such a delightful day.",
			"Watched the sunset, the sky was so colorful.",
			"Explored with friends, we had an amazing adventure.",
			"Rested under a big tree, feeling so peaceful.",
			"Listened to raindrops, the sound is so soothing.",
			"Found a new toy, played with it all day.",
			"Snuggled with my family, feeling loved.",
			"Watched clouds float by, they looked so fluffy.",
			"Listened to the wind, it whispered sweetly.",
			"Discovered a secret place, it's now my favorite spot.",
			"Listened to the waves, they sing a sweet song.",
			"Watched the moon rise, it glows so gently.",
			"Rested in a flower bed, the scent is so lovely.",
			"Listened to the night, it's full of whispers.",
			"Found a new friend, we explored together.",
			"Played with shadows, it was so much fun.",
			"Watched leaves fall, they danced beautifully.",
			"Listened to the world, it's so full of life.",
			"Rested in a cool spot, feeling refreshed.",
			"Watched fireflies glow, they're like tiny stars.",
			"Listened to a lullaby of crickets, it was so sweet.",
			"Found a perfect perch, what a view!",
			"Explored a sunny field, feeling so free.",
			"Listened to the harmony of nature, it's like a symphony.",
			"Watched the morning dew sparkle, so pretty.",
			"Rested on soft moss, it's like a cushion.",
			"Listened to the whispers of trees, so gentle.",
			"Found a hidden nook, it's my secret hideaway.",
			"Watched the world wake up, it's so peaceful.",
			"Listened to birds chirping, they sound so happy.",
			"Rested in a shady spot, feeling cool and relaxed.",
			"Watched the sky change, it's a beautiful show.",
			"Listened to the breeze, it's like a sweet whisper.",
			"Found a new adventure, had the best time!",
			"Watched animals play, they're so joyful.",
			"Listened to the forest hum, it's so soothing.",
			"Rested in a soft bed of leaves, so comfy.",
			"Watched the light dance, it's so magical.",
			"Listened to the gentle rain, it sang to me.",
			"Found a hidden gem, what a special find!",
			"Watched the colors of the sunset, so breathtaking.",
			"Rested in a warm spot, feeling very content.",
			"Listened to nature's melody, it's so calming.",
			"Found a new trail, it led to amazing places.",
			"Watched the twinkling stars, they're so bright.",
			"Rested in a cozy corner, feeling very safe.",
			"Listened to the whispers of the night, so gentle.",
			"Found a favorite spot, it's so peaceful.",
			"Watched the morning light, it greeted me warmly.",
			"Rested in the embrace of nature, feeling blessed.",
			"Listened to the sound of life, it's so comforting.",
			"Found a new friend to share my day with.",
			"Watched the sky turn pink and orange, so beautiful.",
			"Listened to the heartbeat of the forest, it's alive.",
			"Rested in a quiet nook, feeling serene.",
			"Watched the moonlight glow, so enchanting.",
			"Listened to the symphony of night creatures, so melodic.",
			"Found a place to call my own, it's perfect.",
			"Watched the world in silence, it's so calming.",
			"Rested in a soft nest, feeling very snug.",
			"Listened to the harmony of the wild, it's a lullaby.",
			"Found joy in simple things, life is sweet.",
			"Watched the shadows dance, they're playful.",
			"Listened to the call of the night, it's soothing.",
			"Rested in a quiet meadow, feeling at peace.",
			"Watched the stars shimmer, they're like diamonds.",
			"Listened to the whispers of the wind, it's gentle.",
			"Found a place to dream, it's wonderful.",
			"Watched the world from my perch, it's fascinating.",
			"Rested in a hidden grove, feeling protected.",
			"Listened to the gentle hum of nature, it's calming.",
			"Found a secret path, it led to new adventures.",
			"Watched the day turn to night, it's a beautiful transition.",
			"Rested in a soft patch of grass, feeling cozy.",
			"Listened to the night chorus, it's soothing.",
			"Found happiness in the little moments, life is good.",
			"Watched the morning mist, it's so mysterious.",
			"Listened to the forest's whisper, it's comforting.",
			"Rested in a safe place, feeling secure.",
			"Watched the light play, it's so enchanting.",
			"Listened to the rhythm of life, it's peaceful.",
			"Found joy in the beauty of nature, what a good day!"};
	for (size_t i = 0; i < MAX_IDEAS; i++) {
		mIdeas[i] = ideas[i % 100];
	}
	std::cout << "Brain's Default Constructor called." << std::endl;
}

Brain::Brain(Brain const& other)
{
	for (size_t i = 0; i < MAX_IDEAS; i++) {
		mIdeas[i] = other.getIdea(i);
	}
	std::cout << "Brain's Copy Constructor called." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Brain::~Brain()
{
	std::cout << "Brain's Default Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Brain& Brain::operator=(Brain const& rhs)
{
	std::cout << "Brain's Assignment Operator called.";
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	for (size_t i = 0; i < MAX_IDEAS; i++) {
		mIdeas[i] = rhs.getIdea(i);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, Brain const& brain)
{
	os << brain.getIdea(std::rand() % 100) << std::endl;
	return os;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::string Brain::getIdea(size_t const idx) const
{
	return mIdeas[idx];
}

void Brain::setIdea(size_t const idx, std::string idea)
{
	mIdeas[idx] = idea;
}
