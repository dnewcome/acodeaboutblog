using System;
using System.Text.RegularExpressions;

public class Program 
{
	public static void Main()
	{
		while( true )
		{
			Console.WriteLine("Enter regex");
			string strPattern = Console.ReadLine();

			Console.WriteLine("Enter input");
			string strInput = Console.ReadLine();

			Regex re = new Regex( strPattern );
			MatchCollection matches = re.Matches( strInput );
			foreach( Match match in matches )
			{
				Console.WriteLine( "Match: " + match.ToString() );
				foreach( Group group in match.Groups )
				{
					Console.WriteLine( "  Group: " + group.ToString() );
					foreach( Capture capture in group.Captures )
					{
						Console.WriteLine( 
							"    Capture: " + capture.ToString() + 
							" Index: " + capture.Index );
					}
				}
			}
		}
	}
}
