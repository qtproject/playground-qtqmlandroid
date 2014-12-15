package qt.android.support.v7.widget;

import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.content.Context;
import android.support.v7.widget.RecyclerView;

import java.util.ArrayList;
import java.lang.CharSequence;

public class QtRecyclerAdapter extends RecyclerView.Adapter<QtRecyclerAdapter.ViewHolder>
{
    public QtRecyclerAdapter() {
        m_data = new ArrayList<CharSequence>();
    }

    // TODO: adapter.delegate?
    public static class ViewHolder extends RecyclerView.ViewHolder
    {
        public ViewHolder(TextView view) {
            super(view);
        }
        public void bind(CharSequence text) {
            TextView view = (TextView) itemView;
            if (view != null)
                view.setText(text);
        }
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        TextView view = new TextView(parent.getContext());
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        holder.bind(m_data.get(position));
    }

    @Override
    public int getItemCount() {
        return m_data.size();
    }

    public void add(CharSequence title) {
        m_data.add(title);
    }

    private ArrayList<CharSequence> m_data;
}
