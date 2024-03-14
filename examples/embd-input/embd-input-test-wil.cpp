#include "embd-input.h"
#include <stdlib.h>
#include <random>
#include <string.h>

int main(int argc, char** argv) {

    auto mymodel = create_mymodel(argc, argv);
    // int N = 10;
    int max_tgt_len = 64;
    // int n_embd = llama_n_embd(llama_get_model(mymodel->ctx));

    // // add random float embd to test evaluation
    // float * data = new float[N*n_embd];
    // std::default_random_engine e;
    // std::uniform_real_distribution<float>  u(0,1);
    // for (int i=0;i<N*n_embd;i++) {
    //     data[i] = u(e);
    // }

    // eval_string(mymodel, "user: what is the color of the flag of UN?");
    // // eval_float(mymodel, data, N);
    // eval_string(mymodel, "assistant:");
    // eval_string(mymodel, "help me");
    // eval_string(mymodel, mymodel->params.prompt.c_str());

    // std::vector<llama_token> tokens;
    // tokens.push_back(1);
    // tokens.push_back(1371);
    // tokens.push_back(592);
    // eval_tokens(mymodel, tokens);



    int N = 1024; // 3 1024
    int* data = new int[N];
    // data[0] = 1;
    // data[1] = 1371;
    // data[2] = 592;
    // for (int i=0; i<N; i++) data[i] = 32831;
    for (int i=0; i<N; i++) data[i] = i;
    eval_ids(mymodel, data, N);



    // const char* pred;
    // // for (int i=0; i<max_tgt_len; i++) {
    // //     pred = sampling(mymodel);
    // //     if (strcmp(pred, "</s>")==0) break;
    // //     printf("%s", pred);
    // //     fflush(stdout);
    // // }
    // // pred = sampling(mymodel);
    // pred = samplingN(mymodel, max_tgt_len);
    // printf("%s\n\nXXX\n\n", pred);

    // eval_ids(mymodel, data, N);
    // const char* pred2;
    // pred2 = samplingN(mymodel, max_tgt_len);
    // printf("%s\n", pred2);



    int* pred = new int[max_tgt_len];
    int len = samplingN_id(mymodel, pred, max_tgt_len);
    printf("%i tokens\n", len);
    printf("%i %i %i %i\n", pred[0], pred[1], pred[2], pred[3]);
    delete[] pred;



    // // const float* quant = new float[3]{0.1f, 0.2f, 0.3f};
    // float* quant = new float[100]; for (int i=0; i<100; i++) quant[i] = 0.1f;

    // int* pred = new int[max_tgt_len];
    // int len = samplingN_id_wil(mymodel, pred, max_tgt_len, quant);
    // printf("%i tokens\n", len);
    // printf("%i %i %i %i\n", pred[0], pred[1], pred[2], pred[3]);
    // delete[] pred;

    // eval_ids(mymodel, data, N);
    // int* pred2 = new int[max_tgt_len];
    // int len2 = samplingN_id_wil(mymodel, pred2, max_tgt_len, quant);
    // printf("%i tokens\n", len2);
    // printf("%i %i %i %i\n", pred2[0], pred2[1], pred2[2], pred2[3]);
    // delete[] pred2;

    // eval_ids(mymodel, data, N);
    // int* pred3 = new int[max_tgt_len];
    // int len3 = samplingN_id_wil(mymodel, pred3, max_tgt_len, quant);
    // printf("%i tokens\n", len3);
    // printf("%i %i %i %i\n", pred3[0], pred3[1], pred3[2], pred3[3]);
    // delete[] pred3;

    // delete[] quant;



    delete[] data;
    free_mymodel(mymodel);
    return 0;
}
