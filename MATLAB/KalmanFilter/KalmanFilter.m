classdef KalmanFilter < handle
    properties
        m
        P
        model
    end
    methods
        function obj=KalmanFilter(model)
            obj.m = model.m0;
            obj.P = model.P0;
            obj.model = model;
        end
        function [m,P] = updateStep(obj,u)
            %%
            %Fill in with your code here
            obj.m = zeros(length(obj.model.A),1);
            obj.P = eye(length(obj.model.A));
            %%
            m = obj.m;
            P = obj.P;
        end
        function [m,P] = filteringStep(obj,z)
            %%
            %Fill in with your code here
            obj.m = zeros(length(obj.model.A),1);
            obj.P = eye(length(obj.model.A));
            %%
            m = obj.m;
            P = obj.P;
        end
    end
end