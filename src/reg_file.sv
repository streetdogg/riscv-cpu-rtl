/**
 * MIT License
 * 
 * Copyright (c) 2020 Piyush Itankar <pitankar@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

module reg_file (input logic [4:0] rs1a, rs2a, rda,
                 input logic w_en, rs2val,
                 input logic [31:0] rd,
                 output logic [31:0] rs1, rs2);
    /* 32 general purpose registers */
    logic [31:0] x[0:31];

    /* x0 is always set to 0! */
    assign x[0] = 0;

    always_comb begin
        /* Any register needs to be written to? */
        if (w_en) x[rda] = rd;

        /* This is two register manipulation? */
        if (rs2val) rs2 = x[rs2a];
        
        /* rs1 is always needed! */
        rs1 = x[rs1a];
    end
endmodule