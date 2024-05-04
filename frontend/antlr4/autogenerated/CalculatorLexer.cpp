
// Generated from Calculator.g4 by ANTLR 4.12.0


#include "CalculatorLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CalculatorLexerStaticData final {
  CalculatorLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CalculatorLexerStaticData(const CalculatorLexerStaticData&) = delete;
  CalculatorLexerStaticData(CalculatorLexerStaticData&&) = delete;
  CalculatorLexerStaticData& operator=(const CalculatorLexerStaticData&) = delete;
  CalculatorLexerStaticData& operator=(CalculatorLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag calculatorlexerLexerOnceFlag;
CalculatorLexerStaticData *calculatorlexerLexerStaticData = nullptr;

void calculatorlexerLexerInitialize() {
  assert(calculatorlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<CalculatorLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T_ADD", "T_SUB", 
      "T_FUNC", "T_RETURN", "T_ID", "T_DIGIT", "WS", "LineComment", "MultiLineComment"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "','", "'{'", "'}'", "'='", "';'", "'+'", "'-'", 
      "'function'", "'return'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "T_ADD", "T_SUB", "T_FUNC", "T_RETURN", 
      "T_ID", "T_DIGIT", "WS", "LineComment", "MultiLineComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,16,113,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,
  	6,1,7,1,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,11,1,11,5,11,70,8,11,10,11,12,11,73,9,11,1,12,1,
  	12,5,12,77,8,12,10,12,12,12,80,9,12,1,13,4,13,83,8,13,11,13,12,13,84,
  	1,13,1,13,1,14,1,14,1,14,1,14,5,14,93,8,14,10,14,12,14,96,9,14,1,14,1,
  	14,1,15,1,15,1,15,1,15,5,15,104,8,15,10,15,12,15,107,9,15,1,15,1,15,1,
  	15,1,15,1,15,1,105,0,16,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,
  	21,11,23,12,25,13,27,14,29,15,31,16,1,0,5,2,0,65,90,97,122,3,0,48,57,
  	65,90,97,122,1,0,48,57,3,0,9,10,13,13,32,32,2,0,10,10,13,13,117,0,1,1,
  	0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,
  	13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,
  	0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,1,33,1,0,0,
  	0,3,35,1,0,0,0,5,37,1,0,0,0,7,39,1,0,0,0,9,41,1,0,0,0,11,43,1,0,0,0,13,
  	45,1,0,0,0,15,47,1,0,0,0,17,49,1,0,0,0,19,51,1,0,0,0,21,60,1,0,0,0,23,
  	67,1,0,0,0,25,74,1,0,0,0,27,82,1,0,0,0,29,88,1,0,0,0,31,99,1,0,0,0,33,
  	34,5,40,0,0,34,2,1,0,0,0,35,36,5,41,0,0,36,4,1,0,0,0,37,38,5,44,0,0,38,
  	6,1,0,0,0,39,40,5,123,0,0,40,8,1,0,0,0,41,42,5,125,0,0,42,10,1,0,0,0,
  	43,44,5,61,0,0,44,12,1,0,0,0,45,46,5,59,0,0,46,14,1,0,0,0,47,48,5,43,
  	0,0,48,16,1,0,0,0,49,50,5,45,0,0,50,18,1,0,0,0,51,52,5,102,0,0,52,53,
  	5,117,0,0,53,54,5,110,0,0,54,55,5,99,0,0,55,56,5,116,0,0,56,57,5,105,
  	0,0,57,58,5,111,0,0,58,59,5,110,0,0,59,20,1,0,0,0,60,61,5,114,0,0,61,
  	62,5,101,0,0,62,63,5,116,0,0,63,64,5,117,0,0,64,65,5,114,0,0,65,66,5,
  	110,0,0,66,22,1,0,0,0,67,71,7,0,0,0,68,70,7,1,0,0,69,68,1,0,0,0,70,73,
  	1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,24,1,0,0,0,73,71,1,0,0,0,74,78,
  	7,2,0,0,75,77,7,2,0,0,76,75,1,0,0,0,77,80,1,0,0,0,78,76,1,0,0,0,78,79,
  	1,0,0,0,79,26,1,0,0,0,80,78,1,0,0,0,81,83,7,3,0,0,82,81,1,0,0,0,83,84,
  	1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,86,1,0,0,0,86,87,6,13,0,0,87,28,
  	1,0,0,0,88,89,5,47,0,0,89,90,5,47,0,0,90,94,1,0,0,0,91,93,8,4,0,0,92,
  	91,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,97,1,0,0,0,96,
  	94,1,0,0,0,97,98,6,14,0,0,98,30,1,0,0,0,99,100,5,47,0,0,100,101,5,42,
  	0,0,101,105,1,0,0,0,102,104,9,0,0,0,103,102,1,0,0,0,104,107,1,0,0,0,105,
  	106,1,0,0,0,105,103,1,0,0,0,106,108,1,0,0,0,107,105,1,0,0,0,108,109,5,
  	42,0,0,109,110,5,47,0,0,110,111,1,0,0,0,111,112,6,15,0,0,112,32,1,0,0,
  	0,6,0,71,78,84,94,105,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calculatorlexerLexerStaticData = staticData.release();
}

}

CalculatorLexer::CalculatorLexer(CharStream *input) : Lexer(input) {
  CalculatorLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *calculatorlexerLexerStaticData->atn, calculatorlexerLexerStaticData->decisionToDFA, calculatorlexerLexerStaticData->sharedContextCache);
}

CalculatorLexer::~CalculatorLexer() {
  delete _interpreter;
}

std::string CalculatorLexer::getGrammarFileName() const {
  return "Calculator.g4";
}

const std::vector<std::string>& CalculatorLexer::getRuleNames() const {
  return calculatorlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CalculatorLexer::getChannelNames() const {
  return calculatorlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CalculatorLexer::getModeNames() const {
  return calculatorlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CalculatorLexer::getVocabulary() const {
  return calculatorlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CalculatorLexer::getSerializedATN() const {
  return calculatorlexerLexerStaticData->serializedATN;
}

const atn::ATN& CalculatorLexer::getATN() const {
  return *calculatorlexerLexerStaticData->atn;
}




void CalculatorLexer::initialize() {
  ::antlr4::internal::call_once(calculatorlexerLexerOnceFlag, calculatorlexerLexerInitialize);
}