classdef LinearStochasticModel < handle
    %Stochastic model in the form x_{k+1}=Ax_k+Bu_k+w_k
    %z_k = Cx_k+v_k
    %Covariance matrix of w_k is Q_k
    %Covariance matrix of v_k is R_k
    
    properties
        A
        B
        C
        Q
        R
        m0
        P0
        
    end
    methods
        function obj = LinearStochasticModel(A,B,C,Q,R,m0,P0)
            obj.A=A;
            obj.B=B;
            obj.C=C;
            obj.Q=Q;
            obj.R=R;
            obj.P0 = P0;
            obj.m0 = m0;
        end
        function updateModel(obj,A,B,C,Q,R);
            obj.A = A;
            obj.B = B;
            obj.C = C;
            obj.Q = Q;
            obj.R = R;
        end
    end
end