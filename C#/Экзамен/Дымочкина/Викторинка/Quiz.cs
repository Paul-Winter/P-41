namespace Викторинка
{
    public class Quiz
    {
        public string Topic { get; set; } = string.Empty;
        public List<Question> Questions { get; set; } = new List<Question>();
    }
}