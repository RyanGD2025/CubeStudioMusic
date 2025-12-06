import sys
import argparse
from ai_processor import AIProcessor

def main():
    parser = argparse.ArgumentParser(description='Cube Studio Music AI Processing Core.')
    parser.add_argument('--task', required=True, choices=['master', 'separation', 'generation'], help='Tarefa de IA a ser executada.')
    parser.add_argument('--input', required=True, help='Caminho para o arquivo de entrada.')
    parser.add_argument('--output', help='Caminho para o arquivo de saída.')
    parser.add_argument('--stem', nargs='*', help='Hasties a extrair (apenas para separação).')
    
    args = parser.parse_args()

    processor = AIProcessor("models/default.pt")

    if args.task == 'master' and args.output:
        pass

    elif args.task == 'separation':
        pass

if __name__ == '__main__':
    main()
  
