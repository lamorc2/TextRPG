namespace RandomUtils {
    inline std::mt19937 gen(std::random_device{}());

    inline double randomFloat(double min, double max) {
        std::uniform_real_distribution<> dist(min, max);
        return dist(gen);
    }
}