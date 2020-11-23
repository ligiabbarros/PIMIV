# PIMIV

O objetivo do projeto será desenvolver um sistema em C (utilizando o codeblocks –
disponível de forma gratuita no seguinte link: http://www.codeblocks.org/) que será
utilizado pelos hospitais para cadastrar os pacientes que forem diagnosticados com covid-19
e carecem de um acompanhamento e monitoramento. Ao receber o diagnóstico positivo os
profissionais da saúde devem realizar o login no sistema (informando o usuário e a senha) e
informar os dados pessoais do paciente, como Nome, CPF, Telefone, Endereço (Rua, Número,
Bairro, Cidade, Estado e CEP), Data de Nascimento e E-mail, data do diagnóstico e informar
alguma comorbidade do paciente (diabetes, obesidade, hipertensão, tuberculose, outros)
que serão salvos em um Arquivo (a principal vantagem de um arquivo é que as informações
armazenadas podem ser consultadas a qualquer momento).
Após o cadastro, o sistema deverá calcular a idade e verificar se o paciente possui
alguma comorbidade e se pertence ao grupo de risco (maiores de 65 anos). Caso o paciente
pertença ao grupo de risco o sistema deverá salvar em um arquivo de texto o CEP e a idade
do paciente para que essa informação possa ser enviada para a central da Secretaria da
Saúde da cidade.