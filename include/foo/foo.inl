namespace foo {

template <typename T>
T Sum(const std::vector<T>& numbers)
{
    T result{};

    for (const auto& number : numbers)
    {
        result += number;
    }

    return result;
}

} // namespace foo