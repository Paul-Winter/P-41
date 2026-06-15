namespace Викторинка
{
    public class QuizResult
    {
        public string Topic { get; set; } = string.Empty;
        public int BestScore { get; set; }
        public bool Completed { get; set; }
    }
}